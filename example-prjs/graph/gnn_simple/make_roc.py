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
tgt = []

os.makedirs('./tb_data', exist_ok=True)

for i in range(100): #90623
    if i < 10:
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_0000'+str(i)+'.dat', './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_0000'+str(i)+'.dat', './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_0000'+str(i)+'.dat', './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_0000'+str(i)+'.dat', './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_0000'+str(i)+'.dat', './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_0000'+str(i)+'.dat', './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_0000'+str(i)+'.dat')
        with open('./tb_data/tb_output_edge_labels_0000'+str(i)+'.dat', 'r') as res_file:
            for line in res_file.readlines():
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file.readlines():
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list
    elif i < 100:
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_000'+str(i)+'.dat', './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_000'+str(i)+'.dat', './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_000'+str(i)+'.dat', './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_000'+str(i)+'.dat', './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_000'+str(i)+'.dat', './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_000'+str(i)+'.dat', './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_000'+str(i)+'.dat')
        with open('./tb_data/tb_output_edge_labels_000'+str(i)+'.dat', 'r') as res_file:
            for line in res_file:
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file:
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list
    elif i < 1000:
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_00'+str(i)+'.dat', './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_00'+str(i)+'.dat', './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_00'+str(i)+'.dat', './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_00'+str(i)+'.dat', './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_00'+str(i)+'.dat', './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_00'+str(i)+'.dat', './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_00'+str(i)+'.dat')
        with open('./tb_data/tb_output_edge_labels_00'+str(i)+'.dat', 'r') as res_file:
            for line in res_file:
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file:
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list
    elif i < 10000:
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_0'+str(i)+'.dat', './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_0'+str(i)+'.dat', './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_0'+str(i)+'.dat', './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_0'+str(i)+'.dat', './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_0'+str(i)+'.dat', './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_0'+str(i)+'.dat', './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_0'+str(i)+'.dat')
        with open('./tb_data/tb_output_edge_labels_0'+str(i)+'.dat', 'r') as res_file:
            for line in res_file:
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file:
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list
    else:
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_edge_features_'+str(i)+'.dat', './tb_input_edge_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_input_node_features_'+str(i)+'.dat', './tb_input_node_features.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_predictions_'+str(i)+'.dat', './tb_output_edge_predictions.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_output_edge_targets_'+str(i)+'.dat', './tb_output_edge_targets.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_receivers_'+str(i)+'.dat', './tb_receivers.dat')
        copyfile('/scratch/data/vrazavim/exatrkx-neurips19/gnn-tracking/tb_senders_'+str(i)+'.dat', './tb_senders.dat')
        os.system('source /xilinx/Vivado/2019.2/settings64.sh; vivado_hls -f build_prj.tcl')
        copyfile('./myproject_prj/solution_roc/csim/build/tb_output_edge_labels.dat', './tb_data/tb_output_edge_labels_'+str(i)+'.dat')
        with open('./tb_data/tb_output_edge_labels_'+str(i)+'.dat', 'r') as res_file:
            for line in res_file:
                res_list = [float(x) for x in line.split(' ') if x.strip()]
            res = res + res_list

        with open('./tb_output_edge_targets.dat', 'r') as tgt_file:
            for line in tgt_file:
                tgt_list = [float(x) for j, x in enumerate(line.split(' ')) if j < 57 if x.strip()]
            tgt = tgt + tgt_list


res = [round(x) for x in res]
tgt = [round(y) for y in tgt]
result = np.array(res)
target = np.array(tgt)
print("result shape: ", result.shape)
print("target shape: ", target.shape)

fpr, tpr, thresholds = roc_curve(target, result)
#roc_auc = roc_auc_score(result, target)
roc_auc = auc(fpr, tpr)
print("AUC = ", roc_auc)

plt.plot(fpr, tpr, label='ROC curve (area = %0.3f)' % roc_auc)
plt.plot([0, 1], [0, 1], 'k--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.0])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('ROC curve')
plt.legend(loc="lower right")
plt.savefig('csim_roc.pdf')

