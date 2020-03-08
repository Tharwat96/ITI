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
import java.util.Properties;

public class Consumer
{
    String bootstrapServers = "127.0.0.1:9092";
    String groupId = "test";
    Logger logger = LoggerFactory.getLogger(Consumer.class.getName());
    Properties properties = new Properties();
    KafkaConsumer<String, String> consumer;
    Thread thread;

    public Consumer(String topic)
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
            while (true)
            {
                ConsumerRecords<String, String> records = consumer.poll(Duration.ofMillis(100));
                for (ConsumerRecord<String, String> record : records)
                {
                    logger.info("Key: " + record.key() + ", Value: " + record.value());
                }
            }
        });
    }

    public void startThread(){
        this.thread.run();
    }
}
