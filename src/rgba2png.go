package main

import (
    "fmt"
    "os"
    "image"
    "image/color"
    "image/png"
    "flag"
)

var (
    // command line options
    filename *string = flag.String("o", "", "output image file name")

    HEIGHT int
    WIDTH  int
    img image.Image
)

func main() {

    flag.Parse()
    //
    // file, err := os.Open(*filename)
    // defer file.Close()
    // if err != nil {
    //     fmt.Println(err)
    //     return
    // }
    //
    // img, err = png.Decode(file)
    // if err != nil {
    //     fmt.Println(err)
    //     return
    // }

    fmt.Scan(&WIDTH)
    fmt.Scan(&HEIGHT)

    img := image.NewRGBA(image.Rect(0, 0, WIDTH, HEIGHT))

    for i:=0; i<HEIGHT; i++ {
        for j:=0; j<WIDTH; j++ {
            var r, g, b, a uint16
            fmt.Scan(&r, &g, &b, &a)
            img.Set(i, j, color.RGBA64{r, g, b, a})
        }
    }

    f, _ := os.OpenFile(*filename, os.O_WRONLY | os.O_CREATE, 0600)
    defer f.Close()
    png.Encode(f, img)
}
