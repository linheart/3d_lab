#!/bin/bash

go test -coverprofile=coverage.out ./hash_table -v
mkdir -p coverage_html

go tool cover -html=coverage.out -o index.html
mv coverage.out index.html coverage_html/

explorer.exe $(wslpath -w $(realpath coverage_html/index.html))

mkdir -p ser
go build -o ser/main main.go