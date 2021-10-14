package write;

import java.io.*;
public class Propser {
    public static void run(String filename,String content) throws IOException {
        File file=new File(filename);
        OutputStream outputStream=new FileOutputStream(file);
        outputStream.write(content.getBytes());
        outputStream.flush();
    }
}
