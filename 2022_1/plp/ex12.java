// Java

class Ex12 {
  public static void main(String[] args){
    try {
      alt1();
    } catch (Exception a) {
      try {
        alt2();
      } catch (Exception b) {
        alt3();
      }
    }
  }
}
