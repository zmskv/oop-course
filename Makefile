.PHONY: build clean-build

build: 
	mkdir build
	cd ./build; cmake ..; make all

clean-build:
	rm -rf ./build/