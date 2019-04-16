import java.net.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Client {
    private static void writeUsingFiles(String data) {
        try {
            Files.write(Paths.get("output.txt"), data.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String list = new String();

    public static void listFilesForFolder(final File folder, int deep, boolean interesting) throws java.io.IOException{
        if (deep > 3 ) {
            if (!interesting) {
                return;
            }
        }
        for (final File fileEntry : folder.listFiles()) {
            list += new String(new char[deep]).replace("\0", " ");
            if (fileEntry.isDirectory()) {
                list += "d ";
                list += fileEntry.getName();
                list += "\n";
                if(fileEntry.getName().equals("2019-03-24")) {
                    listFilesForFolder(fileEntry, deep+1, true);
                }
                else {
                    listFilesForFolder(fileEntry, deep+1, interesting);
                }
            } else {
                list += fileEntry.getName();
                list += "\n";
            }
        }

        sout.write(list.getBytes());
        list = new String();
        sout.flush();

    }

    public static OutputStream sout;

    public static void main(String[] ar) {
        int serverPort = 9000;
        String address = "68.183.67.250";
        // String address = "127.0.0.1";
        try {
            InetAddress ipAddress = InetAddress.getByName(address);
            Socket socket = new Socket(ipAddress, serverPort);
            socket.setTcpNoDelay(true);
            InputStream sin = socket.getInputStream();
            sout = socket.getOutputStream();

            DataInputStream in = new DataInputStream(sin);
            DataOutputStream out = new DataOutputStream(sout);

            list = new String();
            ///runs/ru/openedu/001/2019-03-24/17-55-02/265385.5fef12b6b3db2e61505c5bff7d3a92b5.1336809/test-00/output.txt
            // final File folder = new File("../vfs-cache/runs/ru/openedu/001/2019-03-24/");
            final File folder = new File("../vfs-cache/problems/ru/openedu/week04/quack/Check.jar");
            listFilesForFolder(folder, 0, false);
    
            // out.writeUTF("Hello_prod\n\r");
            // out.flush();

            // byte[] data = Files.readAllBytes(Paths.get("../vfs-cache/runs/ru/openedu/001/2019-03-24/17-59-33/265392.bf337ff8f17c628b5a1fd30b4dc5c325.1336819/test-02/_result_.xml"));//4952
            // sout.write(data);


            // sout.write(list.getBytes());
            

            // while(sin.available() == 0){

            // }
            // byte[] b = new byte[255];
            // sin.read(b);
            // String line = new String(b);
            // line = String.valueOf(in.readChar());
            // line = in.readUTF();
            // writeUsingFiles(list);
        } catch (Exception x) {
            x.printStackTrace();
        }
    }
}