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