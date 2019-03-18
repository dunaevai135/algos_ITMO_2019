import java.net.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Client {
    public static void listFilesForFolder(final File directory) throws java.io.IOException{
        for(File file : directory.listFiles())
        {
            if (fileEntry.isDirectory()) {

            }
            else {
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
        }

    }
    public static void main(String[] ar) throws java.io.IOException {
        // String directory = "../vfs-cache/problems/ru/openedu/week03/bucket/tests/";
        String directory = ".";
        String hostDomain = "68.183.67.250";
        // String hostDomain = "127.0.0.1";
        int port = 9000;

        File[] files = new File(directory).listFiles();

        Socket socket = new Socket(InetAddress.getByName(hostDomain), port);

        BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
        DataOutputStream dos = new DataOutputStream(bos);

        dos.writeInt(files.length);

        listFilesForFolder();

        dos.close();
    }
}