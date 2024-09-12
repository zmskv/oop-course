.PHONY: build clean-build

build: 
	clean-build
	mkdir build
	cd ./build; cmake ..; make all

clean-build:
	rm -rf ./build/