import com.tharwat.classes.Consumer;
import com.tharwat.classes.Producer;

public class App
{
    public static void main(String[] args)
    {
//        Producer inputProducer = new Producer("input");
//        inputProducer.sendMsg("HELLOOOOOOOOOOOOO");
//        inputProducer.closeConnection();

        Consumer consumer = new Consumer("input");
        consumer.startThread();

    }
}
