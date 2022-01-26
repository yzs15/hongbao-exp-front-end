# Kubernetes 限制可用资源
LAB3 --system-reserved=cpu=20,memory=85Gi
LAB9 --system-reserved=cpu=140,memory=85Gi
HBNJ4  --system-reserved=cpu=76,memory=211Gi

sudo systemctl daemon-reload
sudo systemctl restart kubelet
sudo systemctl status kubelet


sudo vim /etc/systemd/system/kubelet.service.d/10-kubeadm.conf
sudo vim /usr/lib/systemd/system/kubelet.service.d/10-kubeadm.conf


# 更新人端信息
bash scripts/down.sh && bash scripts/deploy.sh wyf@10.101.0.21 &
bash scripts/down.sh && bash scripts/deploy.sh lab3n &
bash scripts/down.sh && bash scripts/deploy.sh hbnj4 &

# 获取 Kubernetes 缩扩容情况
while : ; do kubectl get hpa ; sleep 1 ; done