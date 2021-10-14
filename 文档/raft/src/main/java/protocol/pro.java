package protocol;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class pro {
    public static void time(CountDownLatch latch) throws InterruptedException {
        latch.await(10, TimeUnit.SECONDS);
    }

    public static void retime(CountDownLatch latch) throws InterruptedException {
        latch.await(10, TimeUnit.SECONDS);
    }
}
