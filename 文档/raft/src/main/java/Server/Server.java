package Server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket ss=new ServerSocket(9000,1000);
        while(true) {
            System.out.println("waiting");
            Socket s = ss.accept();
            System.out.println("收到");
        }
    }
}
