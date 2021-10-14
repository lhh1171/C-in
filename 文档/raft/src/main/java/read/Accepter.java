package read;

import org.apache.commons.io.IOUtils;

import java.io.*;

/**
 * @author lqc
 */
public class Accepter {
    public static void run(String formfilename,String tofilename) throws IOException {
        File file1=new File(formfilename);
        InputStream inputStream=new FileInputStream(file1);
        File file2=new File(tofilename);
        OutputStream outputStream=new FileOutputStream(file2);
        IOUtils.copy(inputStream,outputStream);
    }
}
