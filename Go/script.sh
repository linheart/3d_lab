#!/bin/bash

go test -coverprofile=coverage.out ./... -v
go tool cover -html=coverage.out -o index.html
explorer.exe $(wslpath -w $(realpath index.html))

# rm coverage.out