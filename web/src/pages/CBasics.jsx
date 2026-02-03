import { useEffect, useState } from 'react'
import ReactMarkdown from 'react-markdown'
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { oneDark } from 'react-syntax-highlighter/dist/esm/styles/prism'

export default function CBasics() {
  const [content, setContent] = useState('')

  useEffect(() => {
    fetch('/C_BASICS.md')
      .then(r => r.text())
      .then(setContent)
      .catch(() => setContent('# C_BASICS.md를 불러올 수 없습니다.\n\n프로젝트 루트의 C_BASICS.md를 web/public/에 복사해주세요.'))
  }, [])

  return (
    <div className="page-doc">
      <h1>C 기초 용어</h1>
      <p className="muted">Java만 해본 사람을 위한 #include, #define, #ifndef 설명</p>
      <div className="markdown-body">
        <ReactMarkdown
          components={{
            code({ node, inline, className, children, ...props }) {
              const match = /language-(\w+)/.exec(className || '')
              return !inline && match ? (
                <SyntaxHighlighter style={oneDark} language={match[1]} PreTag="div" {...props}>
                  {String(children).replace(/\n$/, '')}
                </SyntaxHighlighter>
              ) : (
                <code className={className} {...props}>{children}</code>
              )
            },
          }}
        >
          {content || '로딩 중...'}
        </ReactMarkdown>
      </div>
    </div>
  )
}
