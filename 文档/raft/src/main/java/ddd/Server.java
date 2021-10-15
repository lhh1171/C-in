package ddd;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Random;

public class Server {
    static String sss="";
    static void t(Random random ,String s) throws IOException {
        Socket  socket = new Socket(s, 9001);
        int num=random.nextInt(2);
        System.out.println(num);
        OutputStream outputStream=socket.getOutputStream();
        outputStream.write(num);
    }
    public static void main(String[] args) throws IOException, InterruptedException {
        InetAddress addr = InetAddress.getByName("main");
        final ServerSocket ss = new ServerSocket(9001, 1000, addr);
        final HashMap<String, Integer> hashMap = new HashMap<String, Integer>();

        Thread t1=
        new Thread(){
            @Override
            public void run() {
                String s0="main";
                String s1="node1";
                String s2="node2";
                String s3="node3";
                Random random=new Random();
                try {

                    t(random,s0);
                    System.out.println("已连接"+s0);
                }catch (Exception e){
                    System.out.println("没有连接上"+s0);
                }
                try {
                    t(random,s1);
                    System.out.println("已连接"+s1);
                }catch (Exception e){
                    System.out.println("没有连接上"+s1);
                }
                try {
                    t(random,s2);
                    System.out.println("已连接"+s2);
                }catch (Exception e){
                    System.out.println("没有连接上"+s2);
                }
                try {
                    t(random,s3);
                    System.out.println("已连接"+s3);
                }catch (Exception e){
                    System.out.println("没有连接上"+s3);
                }
            }
        };
        Thread t2=
        new Thread() {
            @Override
            public void run() {
                while (true) {
                    System.out.println("waiting");
                    try {
                        Socket s = ss.accept();
                        String s1 = s.getInetAddress().toString();
                        int len = 0;
                        InputStream inputStream = s.getInputStream();
                        len = inputStream.read();
                        String str = "";
                        byte[] buf = new byte[1024];
                        //不写的化，-1,活着没参选-1，活着并参选0/1,
                        if (len == 1 || len == 0 || len == -1) {
                            hashMap.put(s1, len);
                        } else {
                            str += (char) len;
                            inputStream.read(buf);
                            for (byte b : buf) {
                                str += (char) b;
                            }
                            System.out.println(str);
                        }
                        if (str.contains(" to be propser")){
                            sss=str;
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    System.out.println("收到");
                }
            }
        };

        Thread t3=
        new Thread() {
            @Override
            public void run() {
                int tcount = 0;
                int fcount=0;
                while (true) {
                    if (!hashMap.containsValue(-1)) {
                        for (String key : hashMap.keySet()) {
                            if (hashMap.get(key) == 1) {
                                tcount++;
                            }
                            if (hashMap.get(key) == 0) {
                                fcount++;
                            }
                        }
                    }
                    if ((tcount >= (hashMap.size() / 2 + 1)&&!sss.contains(" to be propser"))) {
                        System.out.println(ss.getInetAddress().toString() + ":" + ss.getLocalPort() + " to be propser");
                        for (String key : hashMap.keySet()) {
                            String ks = key;
                            String kss = key.split("/")[1];
                            try {
                                Socket socket = new Socket(kss, 9001);
                                OutputStream outputStream = null;
                                outputStream = socket.getOutputStream();
                                outputStream.write((ss.getInetAddress().toString() + ":" + ss.getLocalPort() + " to be propser").getBytes());
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                            tcount = 0;
                            hashMap.clear();
                        }
                    } else if(fcount >= (hashMap.size() / 2 + 1)){
                        System.out.println(ss.getInetAddress().toString() + ":" + ss.getLocalPort() + " is leaner");
                        fcount=0;
                        hashMap.clear();
                    }
                }
            }
        };

        t2.start();
        Thread.sleep(1000);
        t1.start();
        Thread.sleep(1000);
        t3.start();
        }
    }

