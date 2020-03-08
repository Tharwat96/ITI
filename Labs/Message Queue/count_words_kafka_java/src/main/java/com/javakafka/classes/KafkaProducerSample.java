package com.javakafka.classes;

import java.io.UnsupportedEncodingException;
import java.sql.Timestamp;
import java.util.Base64;
import java.util.Properties;
import java.util.Random;

import org.apache.kafka.clients.producer.KafkaProducer;
import org.apache.kafka.clients.producer.ProducerRecord;

import com.google.gson.Gson;
import com.google.gson.JsonObject;


public class KafkaProducerSample
{
    KafkaProducer kp = new KafkaProducer();
    Properties outputProps = new Properties();
        outputProps.put("bootstrap.servers","localhost:9092");
        outputProps.put("acks","0");
        outputProps.put("retries","1");
        outputProps.put("batch.size","20971520");
        outputProps.put("linger.ms","33");
        outputProps.put("max.request.size","2097152");
        outputProps.put("compression.type","gzip");
        outputProps.put("key.serializer","org.apache.kafka.common.serialization.StringSerializer");
        outputProps.put("value.serializer","org.apache.kafka.common.serialization.StringSerializer");
        outputProps.put("kafka.topic","output");

        kp.createProducer(args,outputProps);

    void createProducer(String[] args, Properties properties) throws InterruptedException, UnsupportedEncodingException
    {

        // Create Kafka producer
        org.apache.kafka.clients.producer.KafkaProducer<String, String> producer = new org.apache.kafka.clients.producer.KafkaProducer<String, String>(properties);

        try
        {

            while (true)
            {

                Thread.sleep(1000);
                String id = "device-" + getRandomNumberInRange(1, 5);
                producer.send(new ProducerRecord<String, String>(properties.getProperty("kafka.topic"), id, getMsg(id)));

            }

        } finally
        {

            producer.close();

        }

    }

    public String getMsg(String id) throws UnsupportedEncodingException
    {

        Gson gson = new Gson();

        String timestamp = new Timestamp(System.currentTimeMillis()).toString();

        JsonObject obj = new JsonObject();
        obj.addProperty("id", id);
        obj.addProperty("timestamp", timestamp);
        obj.addProperty("data", Base64.getEncoder().encodeToString("this is my message data ...".getBytes("utf-8")));
        String json = gson.toJson(obj);

        return json;

    }

    private static int getRandomNumberInRange(int min, int max)
    {

        Random r = new Random();
        return r.ints(min, (max + 1)).findFirst().getAsInt();

    }

}