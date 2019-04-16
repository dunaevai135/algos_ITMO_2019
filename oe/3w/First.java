import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class First {
    private static void writeUsingFiles(String data) {
        try {
            // Files.write(Paths.get("output.txt"), data.getBytes());
            Files.write(Paths.get("../vfs-cache/runs/ru/openedu/001/2019-03-24/18-27-13/265418.9ee50955ae2f0a0aa4ac8f62ef4c41ff.1336939/test-08/output.txt"), data.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] ar) {
        // System.out.println();
        writeUsingFiles("epxl");
        // writeUsingFiles("Hello");
        // writeUsingFiles(new File("").getParent());
    }
}