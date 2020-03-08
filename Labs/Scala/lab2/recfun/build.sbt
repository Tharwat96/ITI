
name := "recfun"

version := "0.1"

scalaVersion := "2.13.1"

scalacOptions ++= Seq("-deprecation")

// grading libraries
// libraryDependencies += "junit" % "junit" % "4.10" % "test"

// for recfun
libraryDependencies += "org.scala-lang.modules" %% "scala-parser-combinators" % "1.1.2"

//scala test
libraryDependencies += "org.scalactic" %% "scalactic" % "3.1.1"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.1.1" % "test"

