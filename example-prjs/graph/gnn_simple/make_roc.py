import numpy as np
import matplotlib.pyplot as plt
from itertools import cycle

from sklearn import svm, datasets
from sklearn.metrics import roc_curve, auc
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import label_binarize
from sklearn.multiclass import OneVsRestClassifier
from scipy import interp
from sklearn.metrics import roc_auc_score

import os
import glob
import argparse
import sys
from shutil import copyfile

res = []
prd = []
tgt = []

runCsim = True


os.makedirs('./tb_data', exist_ok=True)

if runCsim:
    for i in range(100): #90623
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_'+'%05d.dat'%i, './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_'+'%05d.dat'%i, './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_'+'%05d.dat'%i, './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_'+'%05d.dat'%i, './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_'+'%05d.dat'%i, './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_'+'%05d.dat'%i, './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_'+'%05d.dat'%i)
        with open('./tb_data/tb_output_edge_labels_'+'%05d.dat'%i, 'r') as res_file:
            for line in res_file.readlines():
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_predictions.dat', 'r') as prd_file:
            for line in prd_file.readlines():
                prd_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            prd = prd + prd_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file.readlines():
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list


result = np.array(res)
prdctn = np.array(prd)
target = np.array(tgt)
print("result shape: ", result.shape)
print("prediction shape: ", prdctn.shape)
print("target shape: ", target.shape)

fpr, tpr, thresholds = roc_curve(target, result)
#roc_auc = roc_auc_score(result, target)
roc_auc = auc(fpr, tpr)
print("CSIM AUC = ", roc_auc)

plt.plot(fpr, tpr, label='ROC curve (area = %0.3f)' % roc_auc)
plt.plot([0, 1], [0, 1], 'k--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.0])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC curve')
plt.legend(loc="lower right")
plt.savefig('csim_roc.pdf')

fpr, tpr, thresholds = roc_curve(target, prdctn)
#roc_auc = roc_auc_score(result, target)
roc_auc = auc(fpr, tpr)
print("PYTHON AUC = ", roc_auc)

plt.plot(fpr, tpr, label='ROC curve (area = %0.3f)' % roc_auc)
plt.plot([0, 1], [0, 1], 'k--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.0])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC curve')
plt.legend(loc="lower right")
plt.savefig('python_roc.pdf')

