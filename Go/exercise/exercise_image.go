package main

import "golang.org/x/tour/pic"
import "image"
import "image/color"

type Image struct{}

func (img Image) ColorModel() color.Model {
	return color.RGBAModel
}

func (img Image) Bounds() image.Rectangle {
	// 自己定的
	w, h := 100, 100
	return image.Rect(0, 0, w, h)
}

func (img Image) At(x, y int) color.Color {
	v := uint8(x % (y + 1))
	return color.RGBA{v, v, 255, 255}
}

func main() {
	m := Image{}
	pic.ShowImage(m)
}
