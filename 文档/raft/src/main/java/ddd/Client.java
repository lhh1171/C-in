package ddd;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        HashMap<String,Integer> hashMap=new HashMap();
        try {
            String s1="main";
            Socket  socket = new Socket(s1, 9001);
            Random random=new Random();
            int num=random.nextInt(2);
            System.out.println(num);
            OutputStream outputStream=socket.getOutputStream();
            outputStream.write(num);
        } catch (Exception e){
            System.out.println("没连接上");
        }
    }
}
