import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class mul {
    public static int findMult(String in){
        int total = 0;
        Pattern pattern = Pattern.compile("mul\\((\\d{1,3}),(\\d{1,3})\\)");
        Matcher matcher = pattern.matcher(in);
        while(matcher.find()){
            int x = Integer.parseInt(matcher.group(1));
            int y = Integer.parseInt(matcher.group(2));
            total +=(x*y);
        }
        return total;
    }
    public static void main(String[] args) {
        String in = null;
        try{
            File file = new File("input.txt");
            Scanner reader = new Scanner(file);
            while (reader.hasNextLine()){
                in += reader.nextLine();
                System.out.println(in);
              }
        } catch (FileNotFoundException e){
            System.out.println("Error");
            e.printStackTrace();
        }
        System.out.println(findMult(in));
    }
}