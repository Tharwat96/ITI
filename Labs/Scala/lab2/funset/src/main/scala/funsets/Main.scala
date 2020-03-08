package funsets

object Main extends App {
  import FunSets._
//  println(contains(singletonSet(1), 1))


  val s1 : FunSets.Set = (x) => x >= 4 && x <=7
  val s2 : FunSets.Set = (x) => x >= 4 && x <=7
  def p: Int => Boolean = (x) => x >= 4
  val set: Set = Set(4)
  val test : Boolean = FunSets.exists(set, p)
   println(test)
  // println(test(5));
  // println(test(6));
  // println(test(2));
  // println(test(0));


}
