import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class mul {
    public static int findMult(String in) {
        int total = 0;

        // Padrões regex
        Pattern pattern= Pattern.compile("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");

        // Matchers
        Matcher matcher = pattern.matcher(in);
        Boolean isDoable = true;
        while (matcher.find()) {
            String match = matcher.group();
            if(match.startsWith("mul") && isDoable){
                Pattern mulPattern = Pattern.compile("mul\\((\\d{1,3}),(\\d{1,3})\\)");
                Matcher matcherMul = mulPattern.matcher(match);
                while (matcherMul.find()) {
                        int x = Integer.parseInt(matcherMul.group(1));
                        int y = Integer.parseInt(matcherMul.group(2));
                        total += (x * y);
                }
            }
            if(match.startsWith("don't()")){
                isDoable = false;
            }
            if(match.startsWith("do()")){
                isDoable = true;
            }
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