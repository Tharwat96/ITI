name := "funset"

version := "0.1"

scalaVersion := "2.13.1"

scalacOptions ++= Seq("-deprecation")

//scala test
libraryDependencies += "org.scalactic" %% "scalactic" % "3.1.1"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.1.1" % "test"
