package protocol;

import read.Accepter;
import write.Propser;

import java.io.IOException;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class TT implements Runnable {
    static AtomicInteger now;
    String filename;
    static String fromfilname;
    public TT(AtomicInteger now,String filename) {
        TT.now=now;
        this.filename=filename;
    }
    public TT(){

    }

    public  void run() {
        if (now.compareAndSet(0,1)){
            try {
                fromfilname=filename;
                pro.time(new CountDownLatch(1));
                Propser.run(filename,"x1");
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(filename+" is poser");
        }else {
            try {
                pro.retime(new CountDownLatch(1));
                Accepter.run(fromfilname,filename);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(filename+" is acpter");
        }
    }
    public void te(){
        String filename1="/opt/Ff/file1.txt";
        String filename2="/opt/Ff/file2.txt";
        String filename3="/opt/Ff/file3.txt";
        AtomicInteger now=new AtomicInteger(0);
//
//        ExecutorService pool1 = Executors.newCachedThreadPool();
//        pool1.submit(new TT(now,filename1));
//        pool1.submit(new TT(now,filename2));
//        pool1.submit(new TT(now,filename3));
        Thread t1=new Thread(new TT(now,filename1));
        Thread t2=new Thread(new TT(now,filename2));
        Thread t3=new Thread(new TT(now,filename3));
        
        t1.start();
        t2.start();
        t3.start();
    }

}
