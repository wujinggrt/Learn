# 使用idea学习spring

#### 一些问题
[csdn博客链接](https://blog.csdn.net/a_bang/article/details/72849483)  
报错：  
[ERROR] Failed to execute goal org.apache.maven.plugins:maven-war-plugin:2.2:war (default-war) on project provider: Error assembling WAR: webxml attribute is required (or pre-existing WEB-INF/web.xml if executing in update mode) -> [Help 1]  
war是关于web， 类似于jar  
如果WebContent/WEB-INF/web.xml文件存在，需要在pom.xml文件中加上maven-war-plugin插件  
```xml
<build>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-war-plugin</artifactId>
                <version>3.0.0</version>
                <configuration>
                    <webResources>
                        <resource>
                            <directory>WebContent</directory>
                        </resource>
                    </webResources>
                </configuration>
            </plugin>
        </plugins>
</build>　
```
如果web.xml文件不存在，则按下面的方式配置。
```xml
<build>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-war-plugin</artifactId>
                <version>3.0.0</version>
                <configuration>  
                    <failOnMissingWebXml>false</failOnMissingWebXml>  
                </configuration>
            </plugin>
        </plugins>
</build>
```

# 配置spring版本
在pom.xml文件中，在propertie可以看到spring.version之类的属性，他们就是spring的版本。  
同理，其他的配件也是一样。  
修改之后就可以得到对应的${spring.version}  
  
xml文件头中的后面的-4.0取消掉了。   

#### jetty的变化
```xml
<plugin>
  <groupId>org.eclipse.jetty</groupId>
  <artifactId>jetty-maven-plugin</artifactId>
  <version>9.4.11.v20180605</version>
</plugin>
```
连包都变了  
[jetty官网](http://www.eclipse.org/jetty/documentation/current/jetty-maven-plugin.html)