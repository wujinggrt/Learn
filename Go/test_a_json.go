package main
 
import (
	"os"
	"fmt"
	"encoding/json"
//	"time"
)
 
type Person2 struct {
	Name string
	Age int
	Sex string
	Hobby []string
}
 
func main() {
	//初始化结构体
//	wek := Person2{"wek",18,"男",[]string{"女","study","play"}}
	var wek2 Person2
 
	/*
	//创建或者打开文件
	file, e := os.Create("./temp.txt")
	if e!=nil{
		fmt.Println("创建文件失败！",e)
	}
	//生成文件编码器
	encoder:= json.NewEncoder(file)
	//使用编码器将结构体编码到文件中
	encode := encoder.Encode(wek)
	if encode!=nil{
		fmt.Println("wek写入文件失败！")
	}
	file.Close()
	//睡两秒
	time.Sleep(2*time.Second)
	*/
	
	//打开文件
	open, i := os.Open("./temp.txt")
	if i!=nil{
		fmt.Println("文件打开失败！")
	}
	//代码执行最后将文件关闭
	defer open.Close()
 
	//生成文件解码器
	decoder := json.NewDecoder(open)
	decode := decoder.Decode(&wek2)
	if decode!=nil{
		fmt.Println("文件反序列化失败！")
	}
	fmt.Println(wek2)
}
