import java.net.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Client2 {
    public static void main(String[] ar) throws java.io.IOException {
        String directory = "../vfs-cache/problems/ru/openedu/week04/brackets/tests/";
        // String directory = ".";
        String hostDomain = "68.183.67.250";
        // String hostDomain = "127.0.0.1";
        int port = 9000;

        File[] files = new File(directory).listFiles();

        Socket socket = new Socket(InetAddress.getByName(hostDomain), port);

        BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
        DataOutputStream dos = new DataOutputStream(bos);

        dos.writeInt(files.length);

        for(File file : files)
        {
            long length = file.length();
            dos.writeLong(length);

            String name = file.getName();
            dos.writeUTF(name);

            FileInputStream fis = new FileInputStream(file);
            BufferedInputStream bis = new BufferedInputStream(fis);

            int theByte = 0;
            while((theByte = bis.read()) != -1) bos.write(theByte);

            bis.close();
        }

        dos.close();
    }
}