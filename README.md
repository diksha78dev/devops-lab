# DevOps Lab

A simple student practical repository for the 10 DevOps experiments in the college experiment list.

## Tools used
- Git and GitHub
- Jenkins
- Apache Maven
- Docker
- Kubernetes (Docker Desktop Kubernetes or another available cluster)

## Project files
- `EXPERIMENTS.md` — procedure, commands, expected results and viva points for all 10 experiments.
- `pom.xml` and `src/` — small Java HTTP application used for Maven, Docker and Kubernetes practice.
- `Dockerfile` — builds the Java application image.
- `Jenkinsfile` — Jenkins pipeline for Maven + Docker CI/CD (Experiment 8).
- `Jenkinsfile-web` — Jenkins pipeline example for the static website (Experiment 6).
- `index.html`, `style.css`, `script.js` — static web application.
- `c-programs/` — five C programs required by Experiment 2.
- `deployment.yaml`, `service.yaml` — Kubernetes resources for Experiment 10.

## Quick start (Windows PowerShell)
Check tools:
```powershell
git --version
java -version
mvn -version
docker --version
kubectl version --client
```

Build and test the Java app:
```powershell
mvn clean test package
```

Run the Java app:
```powershell
java -jar target/devops-lab-1.0-SNAPSHOT.jar
```
Open `http://localhost:8080`.

Build and run with Docker:
```powershell
docker build -t devops-lab:1.0 .
docker run --rm -p 8080:8080 devops-lab:1.0
```
Open `http://localhost:8080`.

## Important
1. Use the procedure in `EXPERIMENTS.md` and follow the exact practical manual given by your faculty if it differs.
2. Jenkins agents must have the tools used by a pipeline installed and available in PATH. Docker commands inside Jenkins require Docker access for that agent.
3. For Experiment 6, the sample deployment uses a local Python HTTP server for a simple demonstration. If your lab specifically requires IIS or `/var/www/html`, use the corresponding instructions in `EXPERIMENTS.md` and ask the lab administrator for the required server permissions.
4. Kubernetes must be enabled and running before applying the YAML files.
5. Do not commit passwords, tokens, or private credentials to GitHub. Add credentials through Jenkins' Credentials page.
