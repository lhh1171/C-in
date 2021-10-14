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

public class Server {
    public static void main(String[] args) throws IOException {
        InetAddress addr = InetAddress.getByName("main");
        final ServerSocket ss = new ServerSocket(9001, 1000, addr);
        final HashMap<String, Integer> hashMap = new HashMap<String, Integer>();

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

                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    System.out.println("收到");
                }
            }
        }.start();

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
                    if (tcount >= (hashMap.size() / 2 + 1)) {
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
                    }
                }
            }
        }.start();
        }
    }

