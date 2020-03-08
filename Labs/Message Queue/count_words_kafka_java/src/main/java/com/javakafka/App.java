package com.javakafka;

import com.javakafka.classes.KafkaProducerSample;

import java.io.UnsupportedEncodingException;
import java.util.Properties;

/**
 * Hello world!
 */
public class App
{
    public static void main(String[] args) throws InterruptedException, UnsupportedEncodingException
    {
        KafkaProducerSample inputProducer = new KafkaProducerSample();
        Properties output = new Properties();
        output.put("bootstrap.servers", "localhost:9092");
        output.put("acks"             , "0");
        output.put("retries"          , "1");
        output.put("batch.size"       , "20971520");
        output.put("linger.ms"        , "33");
        output.put("max.request.size" , "2097152");
        output.put("compression.type" , "gzip");
        output.put("key.serializer"   , "org.apache.kafka.common.serialization.StringSerializer");
        output.put("value.serializer" , "org.apache.kafka.common.serialization.StringSerializer");
        output.put("kafka.topic"      , "output");

        inputProducer.createProducer(args, output);




    }
}
