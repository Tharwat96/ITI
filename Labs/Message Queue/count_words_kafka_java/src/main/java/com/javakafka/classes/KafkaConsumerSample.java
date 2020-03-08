package com.javakafka.classes;

import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Base64;
import java.util.Properties;

import org.apache.kafka.clients.consumer.ConsumerRecord;
import org.apache.kafka.clients.consumer.ConsumerRecords;
import org.apache.kafka.clients.consumer.KafkaConsumer;

import com.google.gson.Gson;



public class KafkaConsumerSample
{

    public static void main(String[] args) throws InterruptedException, UnsupportedEncodingException
    {

        Properties input = new Properties();
        input.put("bootstrap.servers", "localhost:9092");
        input.put("kafka.topic", "input");
        input.put("compression.type", "gzip");
        input.put("key.deserializer", "org.apache.kafka.common.serialization.StringDeserializer");
        input.put("value.deserializer", "org.apache.kafka.common.serialization.StringDeserializer");
        input.put("max.partition.fetch.bytes", "2097152");
        input.put("max.poll.records", "500");
        input.put("group.id", "input");

        runMainLoop(args, input);
    }

    static void runMainLoop(String[] args, Properties properties) throws InterruptedException, UnsupportedEncodingException
    {

        // Create Kafka consumer
        KafkaConsumer<String, String> consumer = new KafkaConsumer<String, String>(properties);

        try
        {

            consumer.subscribe(Arrays.asList(properties.getProperty("kafka.topic")));

            System.out.println("Subscribed to topic " + properties.getProperty("kafka.topic"));

            while (true)
            {
                ConsumerRecords<String, String> records = consumer.poll(100);

                for (ConsumerRecord<String, String> record : records)
                {
                    System.out.printf("partition = %s, offset = %d, key = %s, value = %s\n", record.partition(), record.offset(), record.key(), decodeMsg(record.value()).getData());
                }

            }
        } finally
        {
            consumer.close();
        }

    }

    public static MsgKafka decodeMsg(String json) throws UnsupportedEncodingException
    {

        Gson gson = new Gson();

        MsgKafka msg = gson.fromJson(json, MsgKafka.class);

        byte[] encodedData = Base64.getDecoder().decode(msg.getData());
        msg.setData(new String(encodedData, "utf-8"));

        return msg;
    }
}

