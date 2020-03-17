import com.tharwat.classes.ConsumerCounter;
import com.tharwat.classes.Consumer;
import com.tharwat.classes.Producer;

public class App
{
    public static void main(String[] args)
    {
//        Producer inputProducer = new Producer("input");
//        inputProducer.sendMsg("HELLOOOOOOOOOOOOO");
//        inputProducer.closeConnection();

        ConsumerCounter consumer = new ConsumerCounter("input");
        consumer.startThread();

    }
}
