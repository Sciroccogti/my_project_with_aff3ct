# Using AFF3CT as a library for your codes

[![pipeline status](https://gitlab.com/aff3ct/my_project_with_aff3ct/badges/master/pipeline.svg)](https://gitlab.com/aff3ct/my_project_with_aff3ct/pipelines)

This repository contains some simple code examples. It helps to understand how to use the AFF3CT library in your code.
The first step is to compile AFF3CT into a library.

Get the AFF3CT library:

	$ git submodule update --init --recursive

Compile the library on Linux/MacOS/MinGW:

	$ cd lib/aff3ct
	$ mkdir build
	$ cd build
	$ cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-funroll-loops -march=native" -DAFF3CT_COMPILE_EXE="OFF" -DAFF3CT_COMPILE_STATIC_LIB="ON" -DAFF3CT_COMPILE_SHARED_LIB="ON" -DAFF3CT_LINK_MKL="ON"
	$ make -j4

Compile the library on Windows (Visual Studio project)

	$ cd lib/aff3ct
	$ mkdir build
	$ cd build
	$ cmake .. -G"Visual Studio 15 2017 Win64" -DCMAKE_CXX_FLAGS="-D_CRT_SECURE_NO_DEPRECATE /EHsc /MP4" -DAFF3CT_COMPILE_EXE="OFF" -DAFF3CT_COMPILE_STATIC_LIB="ON" -DAFF3CT_COMPILE_SHARED_LIB="ON"
	$ devenv /build Release aff3ct.sln

Now the AFF3CT library has been built in the `lib/aff3ct/build` folder.

The source codes of the examples are in the `examples/` folder.
You can go in this folder to see the next steps.

Note that those examples are documented [here](https://aff3ct.readthedocs.io/en/latest/user/library/library.html).

# How to install mkl on Ubuntu

Reference: [Intel Doc](https://software.intel.com/content/www/us/en/develop/articles/installing-intel-free-libs-and-python-apt-repo.html)

```Bash
# now get the key:
wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB
# now install that key
sudo apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB
# now remove the public key file exit the root shell
rm GPG-PUB-KEY-INTEL-SW-PRODUCTS-2019.PUB
# Add all repositories at once
sudo wget https://apt.repos.intel.com/setup/intelproducts.list -O /etc/apt/sources.list.d/intelproducts.list
sudo apt-get update
sudo apt install intel-mkl-<VERSION>
# set env
echo "source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64" >> ~/.bashrc
```
