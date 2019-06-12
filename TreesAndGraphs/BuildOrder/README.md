#Question: Build Order

You are given a list of projects and list of dependencies (which is a list of pair of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find the build order that will allow the projects to be built. If there is no valid build order, return an error.

Example:

projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)

output: f, e, a, b, d, c