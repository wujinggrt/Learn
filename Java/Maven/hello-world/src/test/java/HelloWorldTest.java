package com.wujing.mvnbook.helloworld;

import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class HelloWorldTest {
	@Test
	public void testSayHello() {
		HelloWorld h = new HelloWorld();
	        String r = h.sayHello();
		assertEquals("Hello mvn", r);
	}
}

