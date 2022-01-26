yum install -y ntp ntpdate

sudo sed -i "s/0.ubuntu.pool.ntp.org/ntp.ntsc.ac.cn/" /etc/ntp.conf
sudo sed -i 's/1.ubuntu.pool.ntp.org/cn.ntp.org.cn/' /etc/ntp.conf
sudo sed -i 's/2.ubuntu.pool.ntp.org/ntp1.aliyun.com/' /etc/ntp.conf
sudo sed -i 's/3.ubuntu.pool.ntp.org/time1.cloud.tencent.com/' /etc/ntp.conf

chkconfig ntpd on
systemctl start ntpd