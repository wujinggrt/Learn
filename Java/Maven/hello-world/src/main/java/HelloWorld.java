package com.wujing.mvnbook.helloworld;

public class HelloWorld {
	public String sayHello() {
		return "Hello mvn";
	}

	public static void main(String[] args) {
		System.out.println(new HelloWorld().sayHello());
	}
}

