package com.tharwat.classes;

import org.apache.kafka.clients.producer.*;
import org.apache.kafka.common.serialization.StringSerializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Properties;

public class Producer
{
    String topic;
    Properties properties = new Properties();

    final Logger logger = LoggerFactory.getLogger(Producer.class);
    KafkaProducer<String, String> producer;

    public Producer(String topic)
    {
        this.topic = topic;
        String bootstrapServers = "127.0.0.1:9092";
        // 1- create Producer properties
        properties.setProperty(ProducerConfig.BOOTSTRAP_SERVERS_CONFIG, bootstrapServers);
        properties.setProperty(ProducerConfig.KEY_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());
        properties.setProperty(ProducerConfig.VALUE_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());

        // 2- create the producer
        producer = new KafkaProducer<String, String>(properties);
        // 3- create a producer record

        // 4- send data

        // 5- flush and close producer
//        producer.close();
    }

    public void sendMsg(String key, String msg)
    {
        ProducerRecord<String, String> record = new ProducerRecord<String, String>("input", key, msg);
        producer.send(record, new Callback()
        {
            public void onCompletion(RecordMetadata metadata, Exception exception)
            {
                // gets executed every time a record is successfully sent or an exception is thrown
                if (exception == null)
                {
                    logger.info("New metadata received. \n" +
                            "Topic: " + metadata.topic() + "\n" +
                            "Partition" + metadata.partition() + "\n" +
                            "Offset: " + metadata.offset() + "\n" +
                            "Timestamp: " + metadata.timestamp()
                    );


                } else
                {
                    logger.warn("An exception has occurred", exception);
                }
                producer.flush();

            }
        });
    }

    public void closeConnection()
    {
        this.producer.close();
    }
}
