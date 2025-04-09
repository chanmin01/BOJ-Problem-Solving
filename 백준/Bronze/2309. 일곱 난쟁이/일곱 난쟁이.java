import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    ArrayList<Integer> nums = new ArrayList<>();

    int sum = 0;
    for (int i = 0; i < 9; i++) {
      int num = Integer.parseInt(br.readLine());
      nums.add(num);
      sum += num;
    }

    int rest = sum - 100;

    Collections.sort(nums);

    outer: for (int i = 0; i < 9; i++) {
      for (int j = i + 1; j < 9; j++) {
        if (nums.get(i) + nums.get(j) == rest) {
          nums.remove(nums.get(j));
          nums.remove(nums.get(i));
          break outer;
        }
      }
    }

    for (Integer num : nums) {
      System.out.println(num);
    }

  }
}