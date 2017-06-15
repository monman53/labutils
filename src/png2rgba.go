package main

import (
    "fmt"
    "os"
    "image"
    "image/png"
    "flag"
)

var (
    // command line options
    filename *string = flag.String("f", "", "input image file name")

    HEIGHT int
    WIDTH  int
    img image.Image
)

func main() {

    flag.Parse()

    file, err := os.Open(*filename)
    defer file.Close()
    if err != nil {
        fmt.Println(err)
        return
    }

    img, err = png.Decode(file)
    if err != nil {
        fmt.Println(err)
        return
    }

    rect := img.Bounds()
    WIDTH = rect.Max.X-1;
    HEIGHT = rect.Max.Y-1;

    fmt.Printf("%d %d\n", WIDTH, HEIGHT)
    for i:=0; i<HEIGHT; i++ {
        for j:=0; j<WIDTH; j++ {
            r, g, b, a := img.At(i, j).RGBA()
            fmt.Printf("%d %d %d %d\n", r, g, b, a);
        }
        fmt.Printf("\n");
    }
}
