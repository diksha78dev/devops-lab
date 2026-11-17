pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Build and Test') {
            steps {
                script {
                    if (isUnix()) {
                        sh 'mvn clean test package'
                    } else {
                        bat 'mvn clean test package'
                    }
                }
            }
        }
        stage('Build Docker Image') {
            steps {
                script {
                    if (isUnix()) {
                        sh 'docker build -t devops-lab:1.0 .'
                    } else {
                        bat 'docker build -t devops-lab:1.0 .'
                    }
                }
            }
        }
        stage('Deploy Container') {
            steps {
                script {
                    if (isUnix()) {
                        sh 'docker rm -f devops-lab-app || true'
                        sh 'docker run -d --name devops-lab-app -p 8080:8080 devops-lab:1.0'
                    } else {
                        bat 'docker rm -f devops-lab-app'
                        bat 'docker run -d --name devops-lab-app -p 8080:8080 devops-lab:1.0'
                    }
                }
            }
        }
    }
    post {
        success { echo 'CI/CD pipeline completed successfully.' }
        failure { echo 'Pipeline failed. Check Console Output.' }
    }
}
