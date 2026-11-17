# DevOps Practical Experiments — Procedure and Viva Notes

> This guide follows the college experiment list and the manuals/details supplied. Where the provided material did not include a detailed procedure (especially Experiment 1), the steps below are a simple practice outline; confirm the exact wording and activity with your faculty.

---

## Experiment 1 — Introduction to DevOps: Understanding the Culture, Principles and Benefits

**Aim:** Understand DevOps culture, principles and benefits.

**Concept:** DevOps combines development (Dev) and operations (Ops) practices to improve collaboration and software delivery. It encourages shared responsibility, automation, continuous feedback and frequent, reliable releases.

**Practice / demonstration:**
1. Open this GitHub repository and show the application files.
2. Explain the flow: developer changes code → Git commit/push → Jenkins build/test → Docker image → deployment.
3. Identify the tools used in this repository: Git/GitHub, Jenkins, Maven, Docker and Kubernetes.
4. Show the relevant files: `pom.xml`, `Jenkinsfile`, `Dockerfile`, `deployment.yaml`.

**Benefits:** Faster delivery, early error detection, repeatable builds, improved collaboration and more reliable deployments.

**Viva:**
- **What is DevOps?** A culture and set of practices that bring development and operations together.
- **What is CI?** Frequently integrating code and automatically building/testing it.
- **What is CD?** Automating delivery or deployment after successful integration.
- **Why automate?** To reduce repetitive manual work and make results repeatable.

---

## Experiment 2 — Getting Started with Git and Version Control

**Aim:** Use Git to track source-code changes and connect a local repository to GitHub.

**Commands (PowerShell / Git Bash):**
```bash
git --version
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
git status
git add .
git commit -m "Add practical files"
git log --oneline
git remote -v
git push
```

**Demonstration:**
1. Open the `devops-lab` folder.
2. Run `git status` to see the working-tree state.
3. Edit `index.html` and save it.
4. Run `git status`; Git should show the modified file.
5. Stage it with `git add index.html`.
6. Commit with `git commit -m "Update home page"`.
7. Push with `git push`.
8. Refresh the GitHub repository and show the change.

**Five C programs** (in `c-programs/`): Bubble Sort, Linear Search, recursive Factorial, File I/O and Matrix Multiplication.

**Useful commands:**
```bash
git init
git add filename
git commit -m "message"
git branch
git switch -c feature/demo
git switch main
git pull origin main
git push -u origin branch-name
```

**Viva:**
- **What is Git?** A distributed version-control system.
- **What is a repository?** A folder whose changes are tracked by Git.
- **What is a commit?** A saved snapshot of staged changes.
- **What does `git add` do?** Adds changes to the staging area.
- **What does `git status` show?** The state of tracked and untracked changes.

---

## Experiment 3 — Collaborating on Projects using GitHub and Pull Requests

**Aim:** Collaborate using branches and pull requests.

**Procedure:**
1. Clone the repository (for a classmate's repository, use their URL):
   ```bash
   git clone https://github.com/OWNER/REPOSITORY.git
   cd REPOSITORY
   ```
2. Create a feature branch:
   ```bash
   git switch -c feature/update-home
   ```
3. Make a small change in `index.html` and save it.
4. Stage and commit:
   ```bash
   git add index.html
   git commit -m "Update home page"
   ```
5. Push the branch:
   ```bash
   git push -u origin feature/update-home
   ```
6. On GitHub, select **Compare & pull request**, enter a title/description and create the PR.
7. Review the changes and merge the PR (if you have permission).
8. Update local main:
   ```bash
   git switch main
   git pull origin main
   ```

**Viva:**
- **What is a branch?** An independent line of development.
- **What is a pull request?** A request to review and merge proposed changes.
- **Why use PRs?** To review code and discuss changes before merging.
- **What is cloning?** Creating a local copy of a remote repository.

---

## Experiment 4 — Implementing GitFlow Workflow in a Team-Based Scenario

**Aim:** Practice the GitFlow branch model.

**Branches:** `main` stores stable releases; `develop` integrates upcoming work; `feature/*` is for features; `release/*` prepares a release; `hotfix/*` fixes urgent production issues.

**Procedure:**
```bash
git switch main
git pull origin main
git switch -c develop
git push -u origin develop

git switch -c feature/add-message
# Make a small change, then:
git add .
git commit -m "Add feature message"
git push -u origin feature/add-message
```
On GitHub, create a PR from `feature/add-message` into `develop` and merge it.

Create a release branch:
```bash
git switch develop
git switch -c release/v1.0
git push -u origin release/v1.0
```
Create a PR from `release/v1.0` into `main`. After approval/merge, create a GitHub release/tag such as `v1.0`.

Create a hotfix branch:
```bash
git switch main
git switch -c hotfix/fix-home
# Make and commit a small correction:
git add .
git commit -m "Fix home page"
git push -u origin hotfix/fix-home
```
Create a PR from the hotfix branch into `main`; also merge the fix back into `develop` so it is not lost.

**Note:** GitFlow has more than one valid team convention. Follow the branch/PR direction required by your faculty's demonstration.

**Viva:**
- **What is GitFlow?** A branching workflow for organizing feature development and releases.
- **What is a hotfix?** A small urgent correction to a released version.
- **What is a release branch?** A branch used to stabilize a planned release.

---

## Experiment 5 — Automating Builds and Jobs using Jenkins

**Aim:** Automate a software build using Jenkins.

**Requirements:** Jenkins running at `http://localhost:8080`, Git plugin, a Java JDK available to the Jenkins agent, and this repository.

**Freestyle job procedure:**
1. Open Jenkins → **New Item** → enter `DevOps-Lab-Freestyle` → choose **Freestyle project** → OK.
2. Under **Source Code Management**, choose **Git** and enter:
   `https://github.com/diksha78dev/devops-lab.git`
3. Choose branch `*/main`. Public repositories do not need credentials; private repositories need credentials configured in Jenkins.
4. Under **Build Triggers**, optionally select **Poll SCM** and use `H/5 * * * *` (checks approximately every five minutes). This is polling, not an instant GitHub webhook.
5. Under **Build Steps**, choose **Execute Windows batch command** on Windows, or **Execute shell** on Linux.
   - Windows:
     ```bat
     javac HelloWorld.java
     java HelloWorld
     ```
   - Linux:
     ```sh
     javac HelloWorld.java
     java HelloWorld
     ```
   For this repository, the Maven project is a better build example; use `mvn clean package` if Maven is installed on the Jenkins agent.
6. Save → **Build Now** → open the build number → **Console Output**.

**Pipeline concept:** A Jenkinsfile stores pipeline stages as code. The repository's `Jenkinsfile` is used for Experiment 8.

**Viva:**
- **What is Jenkins?** An automation server used for build, test and deployment tasks.
- **What is a Jenkins job?** A configured task Jenkins executes.
- **Freestyle vs Pipeline?** Freestyle is configured mainly through the UI; Pipeline defines workflow as code.
- **What is an agent?** A machine/process that executes pipeline work.

---

## Experiment 6 — Applying CI/CD Principles to Web Development using Jenkins

**Aim:** Automate checkout, build/check and deployment of a simple web app.

**Web files:** `index.html`, `style.css`, `script.js`.

**Local preview (easy demonstration):**
1. Open a terminal in the repository.
2. Run:
   ```bash
   python -m http.server 8000
   ```
3. Open `http://localhost:8000`.

**Jenkins Pipeline:**
1. Create a Jenkins **Pipeline** job.
2. Choose **Pipeline script from SCM** → Git.
3. Enter `https://github.com/diksha78dev/devops-lab.git`, branch `*/main`, and script path `Jenkinsfile-web`.
4. Save → **Build Now** → inspect stage view and Console Output.
5. The example pipeline checks out the repository, checks the expected web files, and copies them to a local `web-deploy` folder in the Jenkins workspace.
6. To preview the deployed copy, open a terminal in that `web-deploy` folder and run `python -m http.server 8000`.

**If the faculty requires IIS:** set the deployment directory to the IIS web root (for example `C:\inetpub\wwwroot`) and ensure the Jenkins agent has permission to write there. If the faculty requires Linux `/var/www/html`, use a Linux agent and ensure the Jenkins user has permission. Do not assume these server paths exist on every lab computer.

**Build trigger:** Poll SCM can be configured with `H/5 * * * *`; a GitHub webhook requires a reachable Jenkins server and webhook configuration.

**Viva:**
- **What is CI?** Automatically integrating and validating code changes.
- **What is CD?** Automatically delivering/deploying successful changes.
- **Why test before deployment?** To avoid deploying files that fail validation.
- **What does checkout do?** Gets repository code into the Jenkins workspace.

---

## Experiment 7 — Introduction to Containerization and Application Deployment using Docker

**Aim:** Build and run a containerized Java application.

**Check Docker:**
```bash
docker --version
docker info
```

**Build the image from the repository root:**
```bash
docker build -t devops-lab:1.0 .
```

**Check the image:**
```bash
docker images
```

**Run the container:**
```bash
docker run --name devops-lab-app -d -p 8080:8080 devops-lab:1.0
```

Open `http://localhost:8080`.

**Useful commands:**
```bash
docker ps
docker logs devops-lab-app
docker stop devops-lab-app
docker rm devops-lab-app
```

**Explanation:** A Dockerfile contains image-build instructions; an image is a read-only template; a container is a running instance of an image.

**Viva:**
- **What is containerization?** Packaging an application and its dependencies in an isolated container.
- **What is an image?** A template used to create containers.
- **What is a container?** A running instance of an image.
- **What is Docker Hub?** A registry for storing and sharing images.

---

## Experiment 8 — Building a CI/CD Pipeline using Docker and Jenkins

**Aim:** Automate source checkout, Maven build/test, Docker image creation and deployment using Jenkins.

**Before running:** Jenkins agent must have Git, Java, Maven and Docker installed and available. The agent must be allowed to access the Docker engine.

**Procedure:**
1. Push the repository and `Jenkinsfile` to GitHub.
2. In Jenkins, choose **New Item** → **Pipeline**.
3. Under Pipeline, choose **Pipeline script from SCM** → Git.
4. Repository URL: `https://github.com/diksha78dev/devops-lab.git`; branch `*/main`; script path `Jenkinsfile`.
5. Save → **Build Now**.
6. Check each stage and Console Output.
7. After a successful build, verify the image and running container on the agent:
   ```bash
   docker images
   docker ps
   ```
8. Open the deployed app at `http://localhost:8080` on the machine running the container.

**Docker Hub (optional extension):** Create Jenkins credentials for Docker Hub, then add login/push stages. Never put a Docker Hub password or access token directly in a Jenkinsfile or GitHub.

**Viva:**
- **What is a pipeline?** An automated sequence of build, test and delivery steps.
- **Why Docker with Jenkins?** Jenkins automates the workflow; Docker packages the application consistently.
- **What is a Jenkinsfile?** A text file that defines a Jenkins Pipeline.
- **What is an image tag?** A label/version used to identify an image.

---

## Experiment 9 — Demonstrating Maven Build Lifecycle for Java Applications

**Aim:** Compile, test and package the Java application using Maven in VS Code.

**Check versions:**
```bash
java -version
mvn -version
```

**Run commands from the folder containing `pom.xml`:**
```bash
mvn clean
mvn validate
mvn compile
mvn test
mvn package
mvn install
```

**Run the packaged application:**
```bash
java -jar target/devops-lab-1.0-SNAPSHOT.jar
```
Open `http://localhost:8080`.

**Important phases:**
- `clean` removes previous build output.
- `validate` checks project configuration.
- `compile` compiles main source.
- `test` runs tests.
- `package` creates the JAR.
- `verify` performs checks on the package.
- `install` places the artifact in the local Maven repository.
- `deploy` publishes to a configured remote repository.

**Viva:**
- **What is Maven?** A Java build and project-management tool.
- **What is `pom.xml`?** Project Object Model file containing project configuration and dependencies.
- **What is a lifecycle?** An ordered set of build phases.
- **Where is the JAR created?** In the `target` directory.

---

## Experiment 10 — Implementing Container Orchestration and Deployment using Kubernetes

**Aim:** Deploy a containerized application using a Kubernetes Deployment and Service.

**Requirements:** Kubernetes cluster running, `kubectl` installed, and Docker image available to the cluster. For Docker Desktop Kubernetes, enable Kubernetes in Docker Desktop settings.

**Verify cluster:**
```bash
kubectl version --client
kubectl cluster-info
kubectl get nodes
```

**Apply the files from the repository root:**
```bash
kubectl apply -f deployment.yaml
kubectl apply -f service.yaml
```

**Verify:**
```bash
kubectl get deployments
kubectl get pods
kubectl get services
kubectl get all
kubectl describe deployment devops-lab
```

**Scale:**
```bash
kubectl scale deployment devops-lab --replicas=5
kubectl get pods
kubectl scale deployment devops-lab --replicas=3
```

**Access:** The Service uses NodePort 30080. Open `http://localhost:30080` if your local Kubernetes setup exposes NodePort on localhost.

**Cleanup:**
```bash
kubectl delete -f deployment.yaml
kubectl delete -f service.yaml
```

**Viva:**
- **What is Kubernetes?** A platform for automating deployment, scaling and management of containerized applications.
- **What is a Pod?** The smallest deployable unit in Kubernetes.
- **What is a Deployment?** A resource that manages replicated Pods and their desired state.
- **What is a Service?** A stable network endpoint for accessing Pods.
- **What is scaling?** Increasing or decreasing the number of application replicas.

---

## Screenshot checklist

Capture your own screenshots during the practical:
- Git status, commit and GitHub repository (Experiments 2–4).
- Jenkins job configuration, successful build and Console Output (Experiments 5–6).
- Docker build, `docker images`, `docker ps` and browser result (Experiments 7–8).
- Maven `compile`, `test`, `package` success and generated JAR (Experiment 9).
- `kubectl get nodes`, deployments, pods, services and application result (Experiment 10).
