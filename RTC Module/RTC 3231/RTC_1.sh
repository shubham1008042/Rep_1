sudo apt-get update
sudo apt-get -y upgrade
sudo apt-get install python-smbus
sudo apt-get install i2c-tools
cd etc/
echo rtc-ds3231 >> modules
sed '$ i\ds3231 0x68 > /sys/class/i2c-adapter/i2c-1/new_device \nsudo hwclock -s' rc.local
sudo hwclock -w


