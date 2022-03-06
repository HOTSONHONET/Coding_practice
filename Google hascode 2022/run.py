# importing modules
import os
from pprint import pprint
import sys


# Config

contributors = {}
projects = {}
total_contibutors = 0
total_projects = 0
OUTPUT_DIR = "outputs"
sys.stdout = open(f"output.txt", 'w')
sys.stdin = open("input.txt", 'r')


# Helper functions
def takeInput():
    total_contibutors, total_projects = tuple(map(int, input().split()))
    for _ in range(total_contibutors):
        c_name, c_numSkills = input().split()
        c_numSkills = int(c_numSkills)
        contributors[c_name] = {}
        for __ in range(c_numSkills):
            skill_name, skill_level = input().split()
            skill_level = int(skill_level)
            contributors[c_name][skill_name] = skill_level

    for _ in range(total_projects):
        p_name, days, score, best_before, numRoles = input().split()
        days, score, best_before, numRoles = tuple(
            map(int, (days, score, best_before, numRoles)))

        projects[p_name] = {
            "days": days,
            "score": score,
            "best_before": best_before,
            "numRoles": numRoles,
            "roles": {}
        }

        for __ in range(numRoles):
            skill_name, skill_level = input().split()
            skill_level = int(skill_level)
            projects[p_name]["roles"][skill_name] = skill_level


def solve():
    pprint(contributors)
    pprint(projects)


if __name__ == "__main__":
    takeInput()
    solve()
