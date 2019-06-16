Newyorkcoin [NYC] 2016-2018 integration/staging tree
===============================================

https://newyorkcoin.io/

What is the Newyorkcoin [NYC] Blockchain?
---------------------------

### Overview
Newyorkcoin is a blockchain project with the goal of offering secured messaging, websites on the chain and an overall pleasing experience to the user.

### Blockchain Technology
Blockchain technology has the capabilities to change a variety of things in the world and can also be the backbone of a new internet. One place that blockchain technology has not had an impact on yet is website on the blockchain. However, Newyorkcoin is trying to change that and is well on their way to doing so.

### Website on the Chain
Newyorkcoin Blockchain will keep sites extremely safe and will make them virtually impenetrable, which is creating a new standard for website safety and security. In addition to the security improvements, Newyorkcoin Blockchain will also ensure that your website is never taken down or removed, no matter what. You will also have complete control of your data, and the sites will feature faster server times.

### Secured Messaging
Developing the usability features: The secured messaging system, masternodes (intuitive node launching and monitoring), smooth sync patch, shrinking blockchain, light clients and much much more.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring Newyorkcoin stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### HMQ1725 Algorithm
We use an custom internal algorithm known as HMQ1725 to sign blocks and conduct other functions, it takes its name from how it was designed: Highly-Modified-Quark 17-Algorithms 25-Scientific-Rounds

Specifications and General info
------------------
Newyorkcoin uses   Boost1.66,
			  OR Boost1.58,  
			  Openssl1.02n,
			  Berkeley DB 6.2.32,
			  QT5.11 to compile


Block Spacing: 5 Minutes
Stake Minimum Age: 90 Confirmations (PoS-v3) | 2 Hours (PoS-v2)

Port: 22442
RPC Port: 22447

Compiling Newyorkcoin daemon on Ubunutu 16.04 LTS Xenial
---------------------------
### Note: guide should be compatible with other Ubuntu versions from 14.04+
### Note: guide updated for compiling with Ubuntu 18.04 LTS Bionic

### Become poweruser
sudo -i

### Dependencies install
cd ~; sudo apt-get install ntp git build-essential libssl1.0-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update; apt-get upgrade; apt-get install git make automake build-essential libboost-all-dev; apt-get install yasm binutils libcurl4-openssl-dev openssl libssl1.0-dev; sudo apt-get install libgmp-dev;

### Dependencies build and link
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib";

### Personal upload EXAMPLE
cd ~; sudo cp -r /home/ftpuser/ftp/files/NYC-clean/. ~/Newyorkcoin

### GitHub pull RECOMMENDED
cd ~; git clone https://github.com/CryptoCoderz/Newyorkcoin

### Build Newyorkcoin daemon
cd ~; cd ~/Newyorkcoin/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x leveldb; chmod a+x ~/Newyorkcoin/src; chmod a+x ~/Newyorkcoin; make -f makefile.unix USE_UPNP=-; cd ~; cp ~/Newyorkcoin/src/Newyorkcoind /usr/local/bin;

### Create config file for daemon
cd ~; sudo ufw allow 22447/tcp; sudo ufw allow 22442/tcp; sudo mkdir ~/.NYC; cat << "CONFIG" >> ~/.NYC/Newyorkcoin.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=newyorkcoinuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=22442
port=22447
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=198.50.180.207
addnode=85.255.7.52
addnode=195.181.211.221
addnode=176.31.205.41
addnode=116.14.167.86
addnode=167.99.171.227
addnode=174.107.102.219
addnode=176.9.156.236
addnode=198.50.180.193
addnode=94.130.64.143
addnode=145.239.65.6
addnode=108.61.175.156
addnode=46.4.27.201
addnode=149.56.154.75
addnode=50.46.99.238
addnode=159.89.114.40

CONFIG
chmod 700 ~/.NYC/Newyorkcoin.conf; chmod 700 ~/.NYC; ls -la ~/.NYC

### Run Newyorkcoin daemon
cd ~; Newyorkcoind; Newyorkcoind getinfo

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling

make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-

License
-------

Newyorkcoin [NYC] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/CryptoCoderz/Newyorkcoin/tags) are created
regularly to indicate new official, stable release versions of Newyorkcoin [NYC].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at https://discord.gg/cn3AfPS .

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
