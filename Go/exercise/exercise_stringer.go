package main

import "fmt"
import "strings"
import "strconv"

type IPAddr [4]byte

// TODO: 给 IPAddr 添加一个 "String() string" 方法
// 例如，IPAddr{1, 2, 3, 4} 应当打印为 "1.2.3.4"。

func (ip *IPAddr) String() string {
	buf := make([]string, len(*ip))
	for i, v := range *ip {
		buf[i] = strconv.FormatInt(int64(v), 10)
	}
	ret := strings.Join(buf, ".")
	return ret
}

func main() {
	hosts := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for name, ip := range hosts {
		fmt.Printf("%v: %v\n", name, &ip)
	}
}