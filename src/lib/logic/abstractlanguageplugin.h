/*
 * Copyright (C) 2014 Canonical, Ltd.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * Neither the name of Nokia Corporation nor the names of its contributors may be
 * used to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef ABSTRACTLANGUAGEPLUGIN_H
#define ABSTRACTLANGUAGEPLUGIN_H

#include <QObject>

class AbstractLanguageFeatures;

class AbstractLanguagePlugin : public QObject
{
    Q_OBJECT

public:
    AbstractLanguagePlugin(QObject *parent = nullptr);
    ~AbstractLanguagePlugin() override;

    virtual void predict(const QString& surroundingLeft, const QString& preedit);
    virtual void wordCandidateSelected(QString word);
    virtual AbstractLanguageFeatures* languageFeature();

    //! spell checker
    virtual void spellCheckerSuggest(const QString& word, int limit);
    virtual void addToSpellCheckerUserWordList(const QString& word);
    virtual bool setLanguage(const QString& languageId, const QString& pluginPath);

signals:
    void newSpellingSuggestions(QString word, QStringList suggestions);
    void newPredictionSuggestions(QString word, QStringList suggestions);
};

#endif // ABSTRACTLANGUAGEPLUGIN_H
