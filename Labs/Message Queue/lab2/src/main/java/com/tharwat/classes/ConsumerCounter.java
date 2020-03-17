package com.tharwat.classes;

import org.apache.kafka.clients.consumer.ConsumerConfig;
import org.apache.kafka.clients.consumer.ConsumerRecord;
import org.apache.kafka.clients.consumer.ConsumerRecords;
import org.apache.kafka.clients.consumer.KafkaConsumer;
import org.apache.kafka.common.serialization.StringDeserializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.Duration;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

public class ConsumerCounter
{
    String bootstrapServers = "127.0.0.1:9092";
    String groupId = "test";
    Logger logger = LoggerFactory.getLogger(ConsumerCounter.class.getName());
    Properties properties = new Properties();
    KafkaConsumer<String, String> consumer;
    Thread thread;

    public ConsumerCounter(String topic)
    {
        properties.setProperty(ConsumerConfig.BOOTSTRAP_SERVERS_CONFIG, bootstrapServers);
        properties.setProperty(ConsumerConfig.KEY_DESERIALIZER_CLASS_CONFIG, StringDeserializer.class.getName());
        properties.setProperty(ConsumerConfig.VALUE_DESERIALIZER_CLASS_CONFIG, StringDeserializer.class.getName());
        properties.setProperty(ConsumerConfig.GROUP_ID_CONFIG, groupId);
        properties.setProperty(ConsumerConfig.AUTO_OFFSET_RESET_CONFIG, "earliest"); // earliest/latest/none

        // create consumer
        consumer = new KafkaConsumer<String, String>(properties);

        // subscribe consumer to topic(s)
        consumer.subscribe(Arrays.asList(topic));
        // poll for new data
        thread = new Thread(() -> {
            Producer outputProducer = new Producer("output");
            String newValue = "";
            while (true)
            {
                ConsumerRecords<String, String> records = consumer.poll(Duration.ofMillis(100));
                for (ConsumerRecord<String, String> record : records)
                {

                    logger.info("Key: " + record.key() + ", Value: " + record.value());
                    HashMap<String, Integer> map = new HashMap<>();

                    for (String word : record.value().split("\\W"))
                    {
                        if (word.isEmpty())
                        {
                            continue;
                        }
                        if (map.containsKey(word))
                        {
                            map.put(word, map.get(word) + 1);
                        } else
                        {
                            map.put(word, 1);
                        }
                    }
                    for (Map.Entry<String, Integer> entry : map.entrySet())
                    {
//                        logger.info(entry.getKey() + ": " + entry.getValue());
                        newValue += entry.getKey() + ": " + entry.getValue() + " ";
                    }
//                    logger.info("newvalue: " + newValue);

                    logger.info("Key: " + record.value() + ", Value: " + newValue);
                    outputProducer.sendMsg(record.value(), newValue);


                }
            }
        });
    }

    public void startThread()
    {
        this.thread.run();
    }
}
