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
        // String directory = ".";
        String directory = "../vfs-cache/runs/ru/openedu/001/2019-03-24/17-59-33/265392.bf337ff8f17c628b5a1fd30b4dc5c325.1336819/test-02/";
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