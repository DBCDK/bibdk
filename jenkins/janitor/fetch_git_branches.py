#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# -*- mode: python -*-

import git
import sys
import getopt
from kubernetes import client, config
import json
import yaml


# Fetch the remote repositories
def lsremote(url):
  remote_refs = {}
  g = git.cmd.Git()
  for ref in g.ls_remote(url).split('\n'):
    hash_ref_list = ref.split('\t')
    if hash_ref_list[1] != 'HEAD':
      if hash_ref_list[1].startswith('refs/heads') :
        remote_refs[hash_ref_list[1]] = hash_ref_list[0]
  return remote_refs


# Get a list of the remote branches.
def list_branches(remotes):
  current_branches = []

  for ref in remotes:
    if ref != 'HEAD':
      current_branches.append(ref.replace('refs/heads/', ''))

  normalized_branches = []

  for branch in current_branches:
    normalized_branches.append(branch.replace(
      'feature/', '').replace('_', '-'))

  return normalized_branches

# fet a list of deployments on kubernetes
def get_deploys():
  '''
  @TODO use the config set in jenkins - there is an error in the kubeconfig
  @TODO delivered by platform. A valid (handmade) kubeconfig is stored in
  @TODO bibdk_config/jenkins/kubeconfig.yaml which is used here
  '''
  conf = config.load_kube_config(config_file='kubeconfig.yaml')
  api_instance = client.AppsV1beta1Api(client.ApiClient(conf))
  api_response = api_instance.list_namespaced_deployment("frontend-features")

  delete_me=[]
  for item in api_response.items:
    name = item.metadata.name
    if(name.startswith('bibliotek-dk')):
      delete_me.append(name)

  print(delete_me)
  return delete_me

def branch_name_from_deploy(deploy_name):
  if deploy_name.startswith('bibliotek-dk-www-'):
    branch_name = deploy_name.replace('bibliotek-dk-www-', '')
    return branch_name

def parse_args(argv):
  deploy_vars = {
    'url': ''
  }
  try:
    opts, args = getopt.getopt(argv, "u:c:")
  except getopt.GetoptError:
    sys.exit(2)

  # print(opts)
  for opt, arg in opts:
    if opt == '-u':
      deploy_vars['url'] = arg
    if opt == '-c':
      deploy_vars['config'] = arg

  return deploy_vars

def delete_on_kubernetes(deploy):
  print(deploy)


if __name__ == "__main__":
  vars = parse_args(sys.argv[1:])
  remotes = lsremote(vars['url'])
  branches = list_branches(remotes)
  print(branches)
  deploys = get_deploys()
  ''''''
  for deploy in deploys:
    branch_name = branch_name_from_deploy(deploy)
    if branch_name and branch_name not in branches:
      delete_on_kubernetes(deploy)





