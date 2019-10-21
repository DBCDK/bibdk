#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# -*- mode: python -*-

import git
import sys
import getopt
from kubernetes import client, config


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

def get_deploys():
  config.load_kube_config(config_file='fisk.txt')
  v1 = client.CoreV1Api()
  print("Listing pods with their IPs:")
  ret = v1.list_pod_for_all_namespaces(watch=False)
  for i in ret.items:
    print("%s\t%s\t%s" % (i.status.pod_ip, i.metadata.namespace, i.metadata.name))
  return 'fisk'

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


if __name__ == "__main__":
  vars = parse_args(sys.argv[1:])
  remotes = lsremote(vars['url'])
  branches = list_branches(remotes)
  deploys = get_deploys()
  print(branches)



