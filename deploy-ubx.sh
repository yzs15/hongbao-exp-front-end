PORT=8085
MAC_TAIL=02
NAME=sun

docker stop $NAME-ubx
docker rm $NAME-ubx
docker run -d \
    -p $PORT:80 \
    -e USER="root" \
    -v /dev/shm:/dev/shm \
    --mac-address 02:42:ac:13:00:$MAC_TAIL \
    -v $HOME/projects/hongbao-fe:/hongbao-fe \
    --device=/dev/ptp0 \
    --device=/dev/ptp1 \
    --name=$NAME-ubx lucaszy/cs101

docker exec -it $NAME-ubx bash


apt-get install -y ibus ibus-clutter ibus-gtk ibus-gtk3 ibus-pinyin

cat <<EOF | tee -a /root/.zshrc
export LANG=zh_CN.utf-8
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus

export LD_LIBRARY_PATH=/hongbao-fe/src/lib:/usr/local/lib:$LD_LIBRARY_PATH
export QT_PLUGIN_PATH=/hongbao-fe/src/lib/qt5/plugins:$QT_PLUGIN_PATH
EOF

sed -i '/ucas/d' /root/.bashrc
sed -i '/cs101/d' /root/.zshrc
mkdir -p /usr/local/lib/
cp -r /hongbao-fe/src/fonts /usr/local/lib/


# 桌面执行
ibus-daemon